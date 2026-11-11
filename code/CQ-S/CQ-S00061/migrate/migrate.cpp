#include<iostream>
#include<algorithm>
using namespace std;
int c,t,n,d;
int m[2000008];
int fd(int x){
	if(m[i-1]<=d&&m[i-2]<=d)
	return 1;
	return 0;}
int sl(int x){
	
	
	
	return 1;
}
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    
    while(t>0){
		t--;
    	cin>>n>>d;
    	for(int i=1;i<=n;i++){
			cin>>m[i];}
		for(int i=1;i<n;i++){
			m[i]=m[i+1]-m[i];}
		for(int i=3;i<=n;i++){
			//ÄÜ·ñ·Éµ½
			if(fd(i)==0)
			continue;
			//Ë«Â·
			if(sl(i)==0)
			continue;
			cnt++;}
		cout<<cnt;
		cnt=0;}

	return 0;
}

