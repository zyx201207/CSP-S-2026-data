#include<iostream>
using namespace std;
const int N=2e5+5;
int n,tmp1=1,tmp2,a[N],tt;
long long ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	tmp2=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(tmp1!=tmp2){
//		cout<<tmp1<<" "<<tmp2<<" "<<ans<<endl; 
		if(tmp1+1==tmp2){
			if(c[tmp1]!=c[tmp2]){
				ans+=min(a[tmp1],a[tmp2]);
			}
			break;
		}
		if(c[tmp1]!=c[tmp2]){
			if(a[tmp1]>a[tmp2]){
				ans+=a[tmp2];
				a[tmp1]-=a[tmp2];
				tmp2--;
				continue;
			}
			if(a[tmp1]==a[tmp2]){
				ans+=a[tmp1];
				tmp1++;
				tmp2--;
				continue;
			}
			if(a[tmp1]<a[tmp2]){
				ans+=a[tmp1];
				a[tmp2]-=a[tmp1];
				tmp1++;
				continue;
			}
		}else{
			if(a[tmp1]>a[tmp2]){
				a[tmp1]-=a[tmp2];
				tmp2--;
				continue;
			}
			if(a[tmp1]==a[tmp2]){
				tmp1++;
				tmp2--;
				continue;
			}
			if(a[tmp1]<a[tmp2]){
				a[tmp2]-=a[tmp1];
				tmp1++;
				continue;
			}
		}
	}
	cout<<ans;
}//9:09
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
