//GZ-J00429 贵州省铜仁市印江县木黄中学 银朗 
#include <iostream>
using namespace std;
int main(){
	string s;
	int x;
	cin>>x;
	int cnt=0;
	for(int i=1;i<=x;i++) {
		int n;
		string m;
		cin>>n>>" ">>m>>endl;
		while(i!=0){
			while(n!=0){
				s=m;
				n--;
				s+=m;
			}
			
		}
	}
	for(i=s.size()-1;i>=0;i--){
		if(s=s[i]){
			cnt=0;
		}
	}
	for(int i=1;i=s.size()-1;i++){
		if(s[i]!=s[(s.size-1)/2+i]{
			cnt++;
		}
	}
cout<<cnt;
	
	retern 0;
};
