#include<iostream>
using namespace std;
int n;
string t;
const int N=1e6+5;
long long ans;
struct iii{
	int a;char b;
}ii[N],iii[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ii[i].a>>ii[i].b;
		iii[n-i+1].a=ii[i].a;
		iii[n-i+1].b=ii[i].b;
	}
	for(int i=1,j=1;j<=n&&i<=n;){
		
		if(ii[i].b==iii[j].b&&ii[i].a==iii[j].a){
			i++;
			j++;
		}else if(ii[i].b!=iii[j].b){
			if(ii[i].a>=iii[j].a){
				ii[i].a-=iii[j].a;
				iii[n-i+1].a-=iii[j].a;
				ans+=iii[j].a;
				iii[j].a=0;
				ii[n-j+1].a=0;
				j++;
			}else{
				iii[j].a-=ii[i].a;
				ii[n-j+1].a-=ii[i].a;
				ans+=ii[i].a;
				ii[i].a=0;
				iii[n-i+1].a=0;
				i++;
			}
		}else{
			if(ii[i].a>=iii[j].a){
				ii[i].a-=iii[j].a;
				iii[n-i+1].a-=iii[j].a;
			//	ans+=iii[j].a;
				iii[j].a=0;
				ii[n-j+1].a=0;
				j++;
			}else{
				iii[j].a-=ii[i].a;
				ii[n-j+1].a-=ii[i].a;
			//	ans+=ii[i].a;
				ii[i].a=0;
				iii[n-i+1].a=0;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}



