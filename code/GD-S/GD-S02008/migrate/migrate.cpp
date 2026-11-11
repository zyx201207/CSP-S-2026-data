#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;

int c,T,n,p,ml[2100000],mr[2100000],bol[2100000];
ll d,ans,x[2100000];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
//	clock_t st=clock();
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c >> T;
	
	while(T--){
		ans=0;
		
		cin >> n >> d;
		
		for (int i=1; i<=n; i++)  cin >> x[i];
		
		for (int i=1; i<=n; i++)  ml[i]=lower_bound(x+1,x+n+1,x[i]-d)-x, mr[i]=upper_bound(x+1,x+n+1,x[i]+d)-(x+1);
		
//		for (int i=1; i<=n; i++)  cout << ml[i]<<" "<<mr[i]<<"\n";
		
		if(c==11 || c==12){
			if(d<x[2]-x[1])  cout<<"0\n";
			else {
				ll k=d/(x[2]-x[1]);
				
				if(k==1)  cout << "0\n";
				else  cout << max(0ll,n-2*k+1) << "\n";
			}
		}
		else if(c==13 || c==14){
			int pp=0,cnt=0,s1=0,s2=0,s3=0,s4=0;
			
			for (int i=1; i<=n; i++){
				if(ml[i]==1 && mr[i]==n)  pp=i, cnt++;
			}
			
			if(cnt>1){
				if(cnt>2)  cout << "0\n";
				else {
					for (int i=1; i<pp-1; i++){
						if(mr[i]==pp)  s1++;
					}
					for (int i=pp+1; i<=n; i++){
						if(ml[i]==pp-1)  s4++;
					}
					
					cout << 1ll*s1*s4 << "\n";
				}
			}
			else {
				for (int i=1; i<pp; i++){
					if(mr[i]==pp+1)  s1++;
					if(mr[i]==pp)  s2++;
				}
				for (int i=pp+1; i<=n; i++){
					if(ml[i]==pp-1)  s3++;
					if(ml[i]==pp)  s4++;
				}
				
				cout << 1ll*s1*s4+1ll*s2*s3 << "\n";
			}
		}
		else {
			
			for (int i=1; i<=n; i++){
				for (int j=i+1; j<=n; j++)  bol[j]=0;
				
				p=i;
				
				for (int j=i+1; j<=n; j++){
					while(mr[p]<j && mr[p]-p)  p=mr[p];
					
					if(mr[p]<j && mr[p]==p){
						
						
						break;
					}
					
					if(ml[j]-p){
						if(ml[j]==p-1){
							if(!bol[p-1] && p-1>i){
								ans++;
								bol[j]=1;
							}
						}
					}
					else {
						if(bol[p] && p>i){
							ans++;
							bol[j]=1;
						}
					}
				}
			}
			
			cout << ans << "\n";
		}
	}
	
//	clock_t endd=clock();
	
//	cout<<"time"<<1.0*(endd-st)/CLOCKS_PER_SEC;
	
	return 0;
}
