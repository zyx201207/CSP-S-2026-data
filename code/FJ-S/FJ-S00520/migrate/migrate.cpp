#include<iostream>
#include<vector>
using namespace std;
long long a[500005];
string olo(string r,int b,int c){
	string j;
	for(int i=b;i<=c;i++){
		j=j+r[i];
	}
	return j;
}
int main(){
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	
	
	for(int q=0;q<t;q++){
	    int all=0;
		long long d;
		int n;
		cin>>n>>d;
		long long x[120005]={0};
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		
		
		
		if((x[n]-x[1])<=d){
			cout<<'0'<<endl;
			return 0;
		}else{
			long long b[120005]={0};
			for(int i=1;i<=n;i++){
				b[i]=a[i]-a[i-1];
			}
			string ts,st;
			for(int i=1;i<=n;i++){
				st+=(b[i]+'0');
				
			}
			for(int i=n-1;i>=0;i++){
				ts=st[i];
				
				
				
			}
			
			for(int i=0;i<n;i++){
				for(int j=i+2;j<n;j++){
					for(int x=0;x<n;x++){
						for(int y=x+2;y<n;y++){
				if(olo(st,i,j)==olo(ts,x,y)){
					all++;
				}
			}
			}
			}
			}
		}
	cout<<all;	
	}
	
	return 0;

}
