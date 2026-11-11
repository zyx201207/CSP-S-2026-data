#include <bits/stdc++.h>
using namespace std;
long long n,d,x[2000010],ans;
int c,t,flag=1;
string s1,s2;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=n;j!=i;j--){
				flag=1;
				for(int k=i,h=1;k<=j;k++,h++){
					if(x[k+1]-x[k]<=n){
						s1[h]+=k;
					}
					else{
						s1=' ';
						flag=0;
						break;
						
					}
				}
				if(flag==1){
					for(int g=i;g<=j;g++){
						if(g>=1&&g<=j-i){
							s2+=g;
						}
						else{
							s2='-1';
							flag=0;
							break;
						}
					}
					
				}	
				if(s1==s2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}	

	return 0;
}

