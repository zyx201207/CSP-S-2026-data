#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		int tong=0;
		int ci=0;
		for(int j=i+1;j<=n;j++){
			string s,s1;
			int x=a[i];int y=a[j];
			while(x!=0){
				s+=x%2;
				x/=2;
			}
			while(y!=0){
				s1+=y%2;
				y/=2;
			}
			int w=0;
			reverse(s.begin(),s.end());
			reverse(s1.begin(),s1.end());
			for(int k=0;k<max(s.size(),s1.size());k++){
				if(s[k]==s1[k] && s[k]==1){
					w++;
				}
			}
			string b;
			int cnt=0;
			int sum=0;
			if(w>=tong){
				tong=w;
				for(int k=0;k<max(s.size(),s1.size());k++){
					b+=s[k]&s1[k];
				}
				reverse(b.begin(),b.end());
				for(int k=0;k<b.size();k++){
					sum+=pow(b[k],cnt);
					cnt++;
				}
				maxn=max(maxn,sum);
				if(ci==0){
					m-=2;
					ci++;
				}else{
					m--;	
				}
			}
			if(m==0){
				break;
			}
		}
	}
	cout << maxn;
	return 0;
}
