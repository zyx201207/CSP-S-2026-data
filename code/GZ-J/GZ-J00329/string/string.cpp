//øº∫≈£∫GZ-J00329
//–’√˚£∫÷£»Ÿ»Ò
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long i[n];
	char c[n];
	for(long long j=0;j<n;j++){
		cin>>i[j]>>c[j];
	}
	
	string s;
	long long l=0;
	for(long long j=0;j<n;j++){
		for(long long k=1;k<=i[j];k++){		
			
		 	s[l]=c[j];
		 	l++;
	}
}
    long long sum=0;
	 if(l%2==0){
	 	for(long long L=l/2-1,R=l/2;L>=0,R<=l-1;L--,R++){
	 		if(s[L]!=s[R]){
	 			sum+=1;
			 }else{
			 	sum+=0;
			 }
		 }
	 	
	 }else{
	 	for(long long L=l/2-1,R=l/2+1;L>=0,R<=l-1;L--,R++){
	 		if(s[L]!=s[R]){
	 			sum+=1;
			 }else{
			 	sum+=0;
			 }
		 }
	 }
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
