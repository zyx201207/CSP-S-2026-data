#include<bits/stdc++.h>
using namespace std;
long long p[200000];
long long d;
long long number[500001];
int check(int a,int b){
 	int f[100];
 	for(int i=0;i<=b-a;i++)
 		f[i]=0;
 	f[0]=1;
 	for(int i=1;i<=b-a;i++){
 		for(int j=i;j>=0;j--){
 			if((p[i]-p[j])>d)
 				break;
 			else
 				f[i]+=f[j];
		 }
	 }
	return f[b];
 }
 int main(){
 	freopen("migrate.in","r",stdin);
 	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
 	int c,t;
 	cin>>c>>t;
 	for(int i=0;i<t;i++){
 		int n;
 		cin>>n>>d;
 		for(int j=0;j<n;j++){
 			cin>>p[j];
		 }
		 int l=0,r=2,num=0;
		 while(r<n){
		 	if(check(l,r)<2){
		 		r++;
			 }
			 else if(check(l,r)>2){
			 	l++;
			 }
			 else{
			 	num++;
			 	r++;
			 }
		 }
		number[t]=num;
	}
	for(int i=0;i<t;i++){
		cout<<number[i]<<endl;
	}
 	return 0;
 }
