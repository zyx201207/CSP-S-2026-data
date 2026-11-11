#include<iostream>
#include<unordered_map>
#include<vector>
#include<math.h>
using namespace std;
long long ans=0;
long long x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n1,d;
		cin>>n1>>d;
		int n=-1;
		for(int i=0;i<n1;i++){
			cin>>x[i];
			if(x[i-1]-x[i]>d&&n==-1){
				n=n1;
			}
		}
		if(n==-1){
			n=n1;
		}else n--;
		//cout<<n<<endl;
		for(int i=0;i<n;i++){
			long long size=0;
			long long left=i,right=i;
			for(int j=i+1;j<n;j++){
				while(right<j){
					int D=x[right]-x[left];
					if(D<=d){
						right++;
					}else{
						size++;
						left=right-1;
					}
				}
				if(size==2){
					ans++;
				}else ;
				//cout<<size<<endl;
			} 
		}
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}
