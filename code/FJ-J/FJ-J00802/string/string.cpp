 #include<bits/stdc++.h>
 using namespace std;
 int a;
 string c;
 string s;
 int main(){
 	freopen("std.in","r",stdin);
	freopen("std.out","w",stdout); 
	int n,m=0,cnt=0;
	cin>>n;
	char b;
	bool f=false;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		m+=a;
		if(c[i]!=b&&i>=2){
			f=true;
		}
		b=c[i];
		for(int j=1;j<=a;j++){
			s+=c[i];
		}
	}
	if(f==false){
		cout<<"0";
		return  0;
	}else{
		if(m%2==0){
			for(int i=0;i<m/2-1;i++){
				if(s[i]!=s[m-1-i]){
					cnt++;
				}
			}	
		}else{
			for(int i=0;i<m/2;i++){
				if(s[i]!=s[m-i]){
					cnt++;
				}
			}
		}
	}
	cout<<cnt;
 	return 0;
 } 
