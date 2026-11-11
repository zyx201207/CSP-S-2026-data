#include<bits/stdc++.h>
using namespace std;

//¿ª longlong!!!!! 

long long c,t;
long long n,d;
long long pl[2000006];



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(long long i=0;i<n;i++){
				cin>>pl[i];
			}
			long long dis=pl[1]-pl[0];
			if(d<2*dis){
				cout<<0<<'\n';
			}else{
				long long len=d/dis;
				if(dis*len==d){
					cout<<max(0ll,n-2*len+1)<<'\n';
				}else{
					cout<<max(0ll,n-2*len+1)<<'\n';
				}
			}
		}
	}else if(c<=2){
//		while(t--){
//			cin>>n>>d;
//			for(int i=0;i<n;i++){
//				cin>>pl[i];
//			}
//			
//		}
	}
    return 0;
}

