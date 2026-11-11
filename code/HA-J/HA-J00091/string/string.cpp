#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int sum=0;
	if(n==1){
		cout<<0;
		return 0;
	}
	string w;
	char s;
	for(int i=1;i<=n;i++){
		int d;
		cin>>d;
		cin>>s;
		w=d*s;
	}
	string e=w;
	reverse(w.begin(),w.end());
	if(e==w){
		cout<<0;
		return 0;
	}
	if(n==2){
		for(int i=0;i<e.size();i++){
			for(int j=e.size();j>=0;j++){
				e[i]=s;
				string f=e;
				reverse(f.begin(),f.end());
				sum++;
				if((e==f)){
					cout<<sum;
					return 0;
				}else{
					continue;
				}
				e[j]=s;
				f=e;
				reverse(f.begin(),f.end());
				sum++;
				if((e==f)){
					cout<<sum;
					return 0;
				}else{
					continue;
				}
			}
		}
	}
	return 0;
}
