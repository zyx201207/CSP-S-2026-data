//石阡县文博中学 刘贝宁 GZ-00561
#include <bits/stdc++.h>
using namespace std;
int n;
string s,s_1;
string s_qian,s_hou;
int n_num[200005];
string s_num[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> n_num[i];
		cin >> s_num[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=n_num[i];j++){
			s=s+s_num[i];
		}
		
	}

	int cnt=0;
		if(s.size()%2==0){
			for(int i=0;i<=s.size()/2-1;i++){
				s_qian+=s[i];
			}
			
			for(int i=s.size()-1;i>=s.size()/2;i--){
				s_hou+=s[i];
			}
			
			for(int i=0;i<=s.size()/2-1;i++){
				if(s_qian[i]!=s_hou[i]){
					cnt++;
				}
			}
			cout << cnt;
		}
		else{
			for(int i=0;i<=s.size()/2-1;i++){
				s_qian+=s[i];
			}
			
			for(int i=s.size()-1;i>=s.size()/2+1;i--){
				s_hou+=s[i];
			}
			
			for(int i=0;i<=s.size()/2-1;i++){
				if(s_qian[i]!=s_hou[i]){
					cnt++;
				}
			}
			cout << cnt;
		}
		
		 
		
	
	return 0;
} 
