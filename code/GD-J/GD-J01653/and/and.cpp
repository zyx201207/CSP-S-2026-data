#include<bits/stdc++.h>
using namespace std;
int n,m;
//struct f{
//	long long cnt,ans;
//}s[200005][200005];
long long a[2005],s[2005][2005],cnt[2005],ai[2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		s[i][1]=a[1];
		cnt[i]=1;
	}
	for(int j=1;j<=n;j++){
		for(int i=j+1;i<=n;i++){
			s[j][i]=(s[j][i-1]&a[i]);
			cnt[j]++;
			if(cnt[j]==m){
				ai[j]=i;
				break;
			}
		}
	}
	int c=-1;
	for(int j=1;j<=n;j++){
//		cout << "s:" << s[j][ai[j]  
		c=max((long long)(c),s[j][ai[j]]);
	}
	cout << c;
	return 0;
}
