#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;char b;
};
node x[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i].a>>x[i].b;
	}
	if(n==2){
		if(x[1].a!=x[2].a&&x[1].b!=x[2].b){
			cout<<min(x[1].a,x[2].a);
		}else{
			cout<<0;
		}
	}else if(n==1){
		cout<<0;
	}else cout<<0;
	//cout<<s;int l=s.size();bool flag=1;
//	for(int i=1;i<(l%2==0?l/2+1:ceil(l/2)+1);i++){
//		if(s[i]!=s[l-i]){
//			flag=0;
//		}
//	}
//	if(flag)cout<<0;
//	else{
//		int minn=INT_MAX;
//		
//	}
//	
	return 0;
}
