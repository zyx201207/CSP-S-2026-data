#include<algorithm>
#include<iostream>
using namespace std;
const int MXN=2e5+1;
long long num[MXN],n,ans;
char c[MXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>num[i]>>c[i];
	}
	int fsti=1,lsti=n,much_f=num[fsti],much_l=num[n];
	while(fsti<=lsti){
		if(much_f==0){
			fsti++;
			much_f=num[fsti];
		}
		if(much_l==0){
			lsti--;
			much_l=num[lsti];
		}
		if(fsti>lsti)break;
		if(c[fsti]!=c[lsti]){
			if(much_f>much_l){
				ans+=much_l;
				much_f-=much_l;
				much_l=0;	
			}else{
				ans+=much_f;
				much_l-=much_f;
				much_f=0;
			}
		}else{
			if(much_f>much_l){
				much_f-=much_l;
				much_l=0;
			}else{
				much_l-=much_f;
				much_f=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
