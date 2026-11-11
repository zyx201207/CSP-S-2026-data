//准考证号：GZ-J00676 学校：遵义市播州区实验学校 姓名：卢煜晨 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long t,c=0;
	cin>>t;
	string s;
	int n[t+10]={0};
	int m[t+10]={0};
	for(int i=0;i<t;i++){
		cin>>n[i];
		cin>>m[i];
		for(int j=1;j<=c;j++){
			s=s+m[i];
		}
	}
	int x=0;
	for(int i=s.size();i<0;i--){
			if(s[i]!=s[x]){
				c++;
			}
			x++;
		}
		cout<<c;
	return 0;
}
