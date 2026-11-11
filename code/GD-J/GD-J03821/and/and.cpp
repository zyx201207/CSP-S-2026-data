#include<iostream>
#include<string>
using namespace std;
string s,q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	  
	int m,n,max=0,start=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
		int rei=2;
		while(s[i]>1){
			q[i]+=s[i]%rei;
			s[i]=s[i]%rei;
			rei*=2;
		}
		if(start){
			if(q[i]&q[i-1]>max){
				max=q[i]&q[i-1];
			}
		}
		start++;
	}
	
	cout<<max;
	return 0;
} 
