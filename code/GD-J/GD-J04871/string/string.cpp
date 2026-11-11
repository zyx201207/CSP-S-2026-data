#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
long long shu[N];
string zi;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	for(int i=1; i<=n; i++) {
		cin>>shu[i]>>zi[i];
		ans+=shu[i];
	}

	long long ans1=ans;
	bool f=0;
	for(int i=1; i<=n; i++) {
		if(zi[1]!=zi[i])f=1;
	}
	if(f==0) {
		cout<<0<<'\n';
		return 0;
	}
	long long m=(ans-1)/2;
	long long cnt=0,www;
	int i=1;
	for(i=1; i<=n; i++) {
		if(cnt+shu[i]==m) {
			cnt+=shu[i];
			ans-=shu[i];
			break;
		} else if(cnt+shu[i]>m) {
			if(m%2==1)m+=1;
			www=shu[i]-(cnt+shu[i]-m);
			ans-=2*www;
			break;
		} else {
			cnt+=shu[i];
		}
	}
	long long was=shu[i]-www,j=i-1,sheng=0,sheng1=0,cnt1=0;
	string a,a1;
	while(i<=n||j>0) {
		if(sheng!=0) {
			if(zi[i]==zi[j]) {
				ans-=sheng;
				sheng1=shu[j]-sheng;
				sheng=0;
			}
			i++;
		} else if(sheng1!=0) {

			if(zi[i]==zi[j]) {
				ans-=sheng1;
				sheng=shu[i]-sheng1;
				sheng1=0;
			}
			j--;
		} else {

			if(shu[i]==shu[j]) {
				if(zi[i]==zi[j]) {
					ans-=shu[i];
				}
				i++;
				j--;
			} else if(shu[i]>shu[j]) {
				if(zi[i]==zi[j]) {
					ans-=shu[j];
				}
				sheng=shu[i]-shu[j];
				j--;
			} else {
				if(zi[i]==zi[j]) {
					ans-=shu[i];
				}
				sheng1=shu[j]-shu[i];
				i++;
			}
		}
	}
	if(ans1%2==1)ans--;
	cout<<ans<<'\n';

	return 0;
}
