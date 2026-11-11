#include<bits/stdc++.h>
using namespace std;
long long n,sum,b,ans=0;
string s;
char a;
long long m[200005];
char w[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b>>a;
		m[i]=b,w[i]=a;
		sum+=b;
		for(int j=1;j<=b;j++)s+=a;
	}
	int cnt=0,tnc=sum,mid=0,f=1;
	for(int i=1;i<=n;i++){
		cnt+=m[i];
		if(cnt>sum/2 && mid==0)mid=i;
		if(i>=2) if(w[i]!=w[i-1]) f=0;
	}
	if(!f){
		for(int i=0;i<=sum/2;i++){	
			if(s[i]!=s[sum-i-1]){
				ans++;
			}
 		}
 		cout<<ans;
//		cnt=0,tnc=n+1;
//		for(int i=1;i<=mid;i++){
//			tnc-=i,cnt+=i;
//			if(w[cnt]==w[tnc]){
//				if(m[cnt]>m[tnc]){
//					m[cnt]-=m[tnc];
//					m[tnc]=0;
//					cnt--;
//				}
//				else{
//					m[tnc]-=m[cnt];
//					m[cnt]=0;
//					tnc++;
//				}
//			}
//			else{
//				if(m[cnt]>m[tnc]){
//					m[cnt]-=m[tnc];
//					ans+=m[tnc];
//					m[tnc]=0;
//					cnt--;
//				}
//				else{
//					m[tnc]-=m[cnt];
//					ans+=m[cnt];
//					m[cnt]=0;
//					tnc++;
//				}
//			}
//			tnc+=i,cnt-=i;
//		}
//		cout<<ans;
	}
	else cout<<0;
	return 0;
}/*
3
2 a
2 b
1 c

3
7 t
4 u
9 a
ttttttt uuu   u aaaaaaaaa

6
2 a
3 b
1 c
2 d
3 e
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
