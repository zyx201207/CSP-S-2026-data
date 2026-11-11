#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in.txt","r",stdin);
	freopen("travel.out.txt","w",stdout);
	int a1,b1;
	string a,b,s="ABC",t="DF";
	cin >>a1>>a>>b1>>b;
	if(a1==b1){
		cout << 1;
		if(a[0]==b[0]&&a[1]==b[1]){
			cout << 1;
			char a2 = a[2];
			char b2 = b[2];
			int s1=0,t1=0;
			for(int i=0;i<=s.size();i++){
				if(a2==s[i]) s1++;
				if(b2==s[i]) s1++;
			}
			for(int i=0;i<=s.size();i++){
				if(a2==t[i]) t1++;
				if(b2==t[i]) t1++;
			}
			if(!(s1==t1)){
				cout << 1;
				
				//cout << a2 <<" " <<b2;
			
				if(a2+1==b2||a2-1==b2){
					cout <<1;
				}
				else if(a2=='F'&&b2=='D'||a2=='D'&&b2=='F')
					cout << 1;
				else
					cout << 0;
			}
			else cout << "00";
		}else cout << "000";
		
	}else cout << "0000";
	
	return 0;
}
 
