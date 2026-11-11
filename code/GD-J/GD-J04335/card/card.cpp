#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in.txt","r",stdin);
	freopen("card.out.txt","w",stdout);
	
	int n,m;
	cin >> n >> m;
	string a,s;
	int b[m+10]={};
	for(int i=1;i<=n;i++){
		char z;
		cin >> z;
		s+=z;
	}
	
	for(int i=0;i<n;i++){
		for(int j=i;i<n;j++){
			char s1 = s[j];
			//cout << s1<<" ";
			for(int k=0;k<a.size();k++){
				if(a[k]==s[j]){
					a = "";
				} 
			}//cout << a <<" ";
			a+=s1;
			
			
		
		} 
		for(int k=0;k<=a.size();k++){
			b[a[k]-'0']++;
		}
	} 
	for(int i=1;i<=m;i++){
		cout << b[i] << " ";
	}
	
	return 0;
}
 
