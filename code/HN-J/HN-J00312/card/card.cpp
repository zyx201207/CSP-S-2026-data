#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[500010];
int b[300010];
string s; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i < n;i++) cin>>a[i];
	for(int i = 0;i < n;i++){
		s = "";
		for(int j = i;j < n;j++){
		//	cout<<a[j];
			bool f = true;
			for(int k = 0;k < s.length();k++){
				if(s[k] == a[j]){
					f = false;
					break;
				}
			}
		//	cout<<s<<endl;
			if(f){
				s = s + a[j];
			}else{
			//	cout<<s;
				int x = 0;
				for(int k = 0;k < s.length();k++){
					if(s[k] == a[j]){
						x = k;
						break;
					}
				}
				string s1 = "";
				for(int k = 0;k < x;k++){
					s1 = s1 + s[k];
				}
				s = s1;
				s = s + a[j];
			}
		}		
		//cout<<"-1";
		for(int j = 0;j < s.length();j++){
			b[s[j]-'0']++;
		}
	//	cout<<-1;
	}
	for(int i = 1;i <= m;i++) cout<<b[i]<<" ";
	return 0;
}
