 #include <bits/stdc++.h>
 using namespace std;
 int c1,c2;
 string s1,s2;
 bool z=true;
 string s3,s4;
 int main(){
 	freopen("travel.in","r",stdin);
 	freopen("travel.out","w",stdout);
 	cin>>c1>>s1>>c2>>s2;
 	if(c1==c2){
 		cout<<1;
	 }
	 else{
	 	cout<<0<<0<<0<<0;
	 	return 0;
	 }
	 if(s1.size()!=s2.size()){
	 	cout<<0<<0<<0;
	 }
	 else{
	 	for(int i=0;i<=s1.size();i++){
	 		if(s1[i]>='0'&&s1[i]<='9'&&s2[i]>='0'&&s2[i]<='9'){
	 			if(s1[i]!=s2[i]){
	 				z=false;
				 }
			 }
			else{
				s3+=s1[i];
				s4+=s2[i];
			}
		 }
		 if(z==true){
		 	cout<<1;
		 	if(s3<="D"&&s4<="D"||s3=="D"&&s4=="F"||s4=="D"&&s3=="F"){
		 		cout<<1;
		 		if(s3<="B"&&s4<="C"||s3<="C"&&s3>="A"&&s4<="B"||s3>="A"&&s3<="C"&&s4<="D"&&s4>="B"||s3>="B"&&s3<="D"&&s4<="C"&&s4>="B"||s3>="C"&&s3<="G"&&s4>"D"&&s4<="G"||s3<="G"&&s3>="D"&&s4<="F"){
		 			cout<<1;
				} 
				 else{
				 	cout<<0;
				 }
			 }
			 else{
			 	cout<<0<<0;
			 }
		 }
		 else{
		 	cout<<0<<0<<0;
		 }
	 }
	return 0;
 }
