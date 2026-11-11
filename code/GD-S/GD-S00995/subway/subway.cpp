#include <bits/stdc++.h>
using namespace std;
struct Node{
	int di=0;
	int d[20][2];
};
int arr[1005];
Node brr[1005];
int c,n,m,d,T;
long long cheng[2005];
void f(int qi,int zhong){
	int a[m],j=0;
	for(int i=0;i<brr[qi].di;i++){
		if(cheng[brr[qi].d[i][0]]==LONG_LONG_MAX){
			a[j]=brr[qi].d[i][0];
			j++;
		}
		cheng[brr[qi].d[i][0]]=min(cheng[qi]+brr[qi].d[i][1],cheng[brr[qi].d[i][0]]);
	}
	j--;
	for(;j>=0;j--){
		f(a[j],zhong);
	}
}
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for(int i=0;i<m;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		int zhang[a],daijia[a];
		for(int j=0;j<a;j++){
			cin>>zhang[j]>>daijia[j];
			zhang[j]--;
		}
		for(int j=0;j<a;j++){
			for(int f=j+1;f<a;f++){
				for(int h=0;h<brr[zhang[f]].di;h++){
					if(brr[zhang[f]].d[brr[zhang[f]].di][0]==zhang[f]){
						brr[zhang[f]].d[brr[zhang[f]].di][0][1]=min(brr[zhang[f]].d[brr[zhang[f]].di][0][1],daijia[f]+daijia[j]);
						continue;
					}
				}
				brr[zhang[f]].d[brr[zhang[f]].di][0][1]=daijia[f]+daijia[j];
				brr[zhang[f]].d[brr[zhang[f]].di][0][0]=zhang[f];
				brr[zhang[f]].di++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<brr[i].di;j++){
			cout<<i+1<<" "<<brr[i].d[j][0]+1<<" "<<brr[i].d[j][1]<<endl;
		}
	}
	while(T--){
		int qi,zhong;
		cin>>qi>>zhong;
		qi-=1;
		zhong-=1;
		long long ans=arr[qi]+arr[zhong];
		for(int i=0;i<m;i++){
			cheng[i]=LONG_LONG_MAX;
		}
		cheng[qi]=0;
		f(qi,zhong);
		cout<<ans+cheng[zhong]<<endl;
	}
	return 0;
}
