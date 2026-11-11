#include<bits/stdc++.h>
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	int a,b[10000],sum=0,c,d,e;
cin>>a>>c;
for(int i=1;i<=a;i++){
	cin>>b[i];
}
sort(b+1,b+a+1);
if(c==2){
	cout<<b[a] and b[a-1];
}
if(c==3){
	cout<<b[a] and b[a-1] and b[a-2];
}
if(c==4){
	cout<<b[a] and b[a-1] and b[a-2] and b[a-3];
}
if(c==5){
		cout<<b[a] and b[a-1] and b[a-2] and b[a-3] and b[a-4];
}
if(c==6){
		cout<<b[a] and b[a-1] and b[a-2] and b[a-3] and b[a-4] and b[a-5];
}
cout<<sum;
//fclose(stdin);
//fclose(stdout);
//Trick||Treat!
	return 0;
}
