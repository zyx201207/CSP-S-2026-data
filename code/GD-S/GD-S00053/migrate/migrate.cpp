#include<bits/stdc++.h>
using namespace std;
int a[5005];
int b_s[5005];
int b_low[5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==11 or c==12){
		for(int I=0;I<t;I++){
			long long n,d;
			long long x,y;
			cin>>n>>d>>x>>y;
			x=y-x;
			//cout<<n<<" "<<d<<" "<<x<<endl;
			char p;
			p=getchar();
			for(int i=0;i<n-2;){
				p=getchar();
				if(!((p<='9' and p>='0')or(p=='-'))){
					i++;
				}
			}
			d/=x;
			if(d==1 or d==0){
				cout<<0<<endl;
				continue;
			}
			if(n-1-(2*d)<0){
				cout<<0<<endl;
				continue;
			}
			cout<<n+1-(2*d)<<endl;
		}
		return 0;
	}
	int n,d;
	for(int I=0;I<t;I++){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int k=0;k<n-1;k++){
			for(int i=0;i<n;i++){
				b_low[i]=10000000;
				b_s[i]=0;
			}
			b_low[k]=0;
			b_s[k]=1;
			for(int i=k;i<n;i++){
				if(b_s[i]==2){
					ans++;
				}
				int j=i+1;
				for(;a[j]-a[i]<=d and j<n;j++){
					if(b_low[i]+1<b_low[j]){
						//cout<<"0001000"<<j<<endl;
						b_low[j]=b_low[i]+1;
						b_s[j]=b_s[i];
					}
					else if(b_low[i]+1==b_low[j]){
						//cout<<"0002000"<<j<<endl;
						b_s[j]+=b_s[i];
					}
				}
			}
		}
		cout<<ans<<endl;		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
