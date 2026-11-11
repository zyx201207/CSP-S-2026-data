#include<bits/stdc++.h>
using namespace std;
int arr[100001]={},ans=0,a,b;
bool fr[100001]={}; 
void f(int x,int y){
	if(x==0){
		ans=max(ans,y);
		return;
	}else{
		for(int i=0;i<a;i++){
			if(fr[i]!=1){
				fr[i]=1;
				f(x-1,(y&arr[i]));
				fr[i]=0;
			}
		}return;
	}
}int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a;i++)cin>>arr[i];
	f(b,2147483647);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
} 
