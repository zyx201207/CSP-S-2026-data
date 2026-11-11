//GZ-J00538 遵义市汇川区周林学校 黎辰阳 
#include<bits/stdc++.h>
using namespace std;
int main(){
	
	froepen("string.in","r",stdin);
	froepen("string.out","w",stdout);
	
	string s=" ",s1=" ";
	int n;
	long long a,sum=0;
	char c;
	cin>>n;
	int l=s.size();
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s += c;
		}
	}
	for(int i=l;i>=1;i--){
		s1 += s[i];
	}
	for(int i=1;i<=l;i++){
		if(s1[i]==s[i]){
			f = 1;
		}	
		else{
			f = 0;
			sum++;
			break;
		}
	}
	if(f==1){
		cout<<0;
	}
	else if(f==0){
		cout<<sum;
	}
	return 0;
}

