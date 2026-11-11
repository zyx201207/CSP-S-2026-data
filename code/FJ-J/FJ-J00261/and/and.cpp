#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
struct node{
	int num,cnt,mark;
};
int num(int x,int y){
	int p=1,q=0;
	while(x&&y){
		q+=((x%2)&&(y%2))*p;
		x/=2,y/=2;
		p*=2;
	}
	return q;
}
bool cmp(int a,int b ){
	return a<b;
}
void s(int nm,int cnt,int mark){
	if(mark==m){
		ans=max(ans,cnt);
		return;
	}
	for(int i=nm+1;i+m-mark-1<n;i++){
	s(i,num(cnt,a[i]),mark+1);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(m==n)ans=num(ans,a[i]);
		if(m==1)ans=max(ans,a[i]);
	}
if(m==n)cout<<ans;
else if(m==1){
	cout<<ans;
}else {
	for(int i=0;i+m<n;i++){
		s(i,a[i],1);
	}cout<<ans;
}
	return 0; 
} 

