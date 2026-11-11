 #include<bits/stdc++.h>
 using namespace std;
 int main(){
 	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
 	int n,a[200005],ans=0;
 	char c;
 	string s="",t="",s1="";
 	cin>>n;
 	for(int i=0;i<n;i++){
 		cin>>a[i]>>c;
 		for(int j=0;j<a[i];j++)s=s+c;
	 }
	 for(int i=s.size()-1;i>0;i--)t=t+s[i];
	 if(t==s){
	 	cout<<"0";
	 	return 0;
	 }
	 
	 if(t!=s){
	 	int l=s.size();
	 	t="";
	 	for(int i=0;i<l/2;i++){
	 		
	 		t=t+s[i];
		 }
		 for(int i=s.size()-1;i>=0;i--){
		 	s1=s1+s[i];
		 }
		 for(int i=0;i<l/2;i++){
		 	if(s1[i]!=t[i])ans++;
		 }
	 }
	 cout<<ans;
	 return 0;
 	
 }
