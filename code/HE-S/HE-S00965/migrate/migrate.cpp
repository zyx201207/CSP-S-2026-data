#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
long long x[2000005];
int main(){
cin>>c>>t;
int ans[100005];
for(int q=0;q<t;q++){
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>x[i];
		}
	if(d>n){
		ans[q]=0;
		continue;
	}
	ans[q]=0;
	for(int i=d;i<n;i++){
		int w;
		w=abs(x[i]);
		if(w<d) continue;
		w-=d;
		ans[q]+=w/d;
	}
}
for(int i=0;i<t;i++){
	cout<<ans[i]<<endl;
}
	return 0;
} 
