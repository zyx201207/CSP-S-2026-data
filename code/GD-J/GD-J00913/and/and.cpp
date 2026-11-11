#include <bits/stdc++.h>
using namespace std;
struct Node{
	int a,b;
};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	Node arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].a;
		arr[i].b=arr[i].a;
	}
	int ci=n-1,pan=1<<29,ans=0;
	for(int i=0;i<30;i++){
		int p=0;
		for(int j=0;j<=ci;j++){
			if(arr[j].b>=pan){
				arr[j].b-=pan;
				int a=arr[j].b;
				arr[j].b=arr[p].b;
				arr[p].b=a;
				a=arr[j].a;
				arr[j].a=arr[p].a;
				arr[p].a=a;
				p++;
			}
		}
		if(p>=m){
			ci=p;
			ans+=pan;
		}
		pan/=2;
	}
	cout<<ans;
	return 0;
}
