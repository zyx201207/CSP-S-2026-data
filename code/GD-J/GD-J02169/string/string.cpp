#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int n,st=1,en;
long long cnt;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	en=n;
	vector<pair<int,char>> v(n+1,make_pair(0,' '));
	for(int i=1; i<=n; i++) {
		int a=0;
		char c=' ';
		scanf("%d %c",&a,&c);
		v[i]=make_pair(a,c);
	}
	while(st<en) {
		int sa=v[st].first,ea=v[en].first;
		char sc=v[st].second,ec=v[en].second;
		if(sc==ec) {
			if(sa==ea) {
				st++;
				en--;
			}
			else if(sa>ea) {
				v[st].first-=ea;
				en--;
			}
			else {
				v[en].first-=sa;
				st++;
			}
		}
		else {
			if(sa==ea) {
				cnt+=1ll*sa;
				st++;
				en--;
			}
			else if(sa>ea) {
				cnt+=1ll*ea;
				v[st].first-=ea;
				en--;
			}
			else {
				cnt+=1ll*sa;
				v[en].first-=sa;
				st++;
			}
		}
	}
	printf("%lld",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
