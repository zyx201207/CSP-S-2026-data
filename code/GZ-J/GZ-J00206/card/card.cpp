//GZ-J00206 杨俊毅 遵义市南白初级中学 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int main(){
  freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
    cin>>n>>m;
//    set <int> q(n,0);
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
//	for(int i=1;i<=n;i++){
//		deque <int> q;
//		bool p=0;
//		for(int x : q){
//			if(x=a[i]){
//				p=1;
//			}
//		}
//		if(q==0){
//			
//		}
//	}
   sort(a+1,a+1+n);
   for(int i=n;i>n-m;i--){
   	cout<<a[i]<<" ";
   }
	return 0;
}

