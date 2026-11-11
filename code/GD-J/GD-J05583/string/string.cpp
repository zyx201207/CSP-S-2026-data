#include<bits/stdc++.h>
using namespace std;
string w;
int n,k,cnt=0,p=0,sumn=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char l;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k>>l;
		sumn+=k;
		for(int o=1;o<=k;o++){
			w+=l;
		}
	}
	int i=0,j=w.size()-1;
	while(i<=j){
		if(w[i]!=w[j]){
			cnt++;
		}else{
			p++;
		}
		i++;
		j--;
	}
	if(p==sumn){
		cout<<0;
		return 0;
	}else{
		cout<<cnt; 	
	}	 
	return 0;
}
