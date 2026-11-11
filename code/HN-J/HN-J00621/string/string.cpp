 #include<bits/stdc++.h>
 using namespace std;
 int n;
 string s;
 int to_string(string s){
 	int mid=s.size()/2,ans=0;
 	string s2;
 	for(int i=s.size()-1;i>=mid;i--){
 		s2+=s[i];
 		if(s[i]!=s[s.size()-i-1]) ans++;
	}
	return ans;
 }
 int main(){
 	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
 	cin>>n;
 	for(int i=0;i<n;i++){
 		int a;
 		char c;
 		cin>>a>>c;
 		for(int j=0;j<a;j++) s+=c;
	}
	int ans=to_string(s);
	cout<<ans;
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
 }
