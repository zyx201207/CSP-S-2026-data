#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	struct pp{
	int a;
	char b;
};
	 int i,j,n,m=0,k=0,sum=0,w,d;
	 cin>>n;
	 pp c[n];
	 for(i=0;i<n;i++){
	 	cin>>c[i].a>>c[i].b;
	 }
	 for(i=0;i<n;i++){
	 	sum+=c[i].a;
	 }
	 char s[sum];
	 w=sum;
	 sum=0;
	 for(i=0;i<n;i++){
	 	for(j=0;j<c[i].a;j++){
	 		s[m]=c[i].b;
	 		m++;
		 }
	 }
	 if(w%2==0){
	 	for(i=0;i<w/2;i++){
	 		if(s[1+k]!=s[n-k]){
	 			k++;sum++;
			 }else{
			 	k++;
			 }
		 }
	 }else{
	 	for(i=0;i<w/2+1;i++){
	 		if(s[1+k]!=s[n-k]){
	 			k++;sum++;
			 }else{
			 	k++;
			 }
		 }
	 }
	 cout<<sum; 
	fclose(stdin);fclose(stdout);
	return 0;
}

