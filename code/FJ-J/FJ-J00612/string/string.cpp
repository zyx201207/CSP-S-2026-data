#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
long long n,m[N],an;
string s[N],ss;
bool h(string s){
	string s1=s;
	reverse(s1.begin(),s1.end());
	return s==s1;
}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>s[i];
	}
//	if(h(s)==1){
//		cout<<"0";
//		return 0;
//	}
	if(n<=1){
		cout<<"0";
		return 0;
	}
//	else if(n==2){
//		
//			cout<<min(m[1],m[2]);
//			return 0;
//		
//	}
	int i=1,j=n;
	while(i<j){
		
		if(s[i]!=s[j]){
			//cout<<114514;
			if(m[i]<m[j]){
				an+=m[i];
				m[j]-=m[i];
				i++;
				
			}
			else if(m[i]>m[j]){
				an+=m[j];
				m[i]-=m[j];
				j--;
				
			}
			else{
				an+=m[i];
				i++;
				j--;
			}
			
		}
		else{
			if(m[i]==m[j]){
				i++;
				j--;
			}
			else if(m[i]<m[j]){
				m[j]-=m[i];
				i++;
			}
			else{
				m[i]-=m[j];
				j--;
			}
		}
		
		
		
	}
	
	
	cout<<an;
	return 0;
}











