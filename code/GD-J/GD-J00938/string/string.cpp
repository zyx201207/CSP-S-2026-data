#include<bits/stdc++.h>
using namespace std;
long long a=0,sum=0;
string c;
string d,e;
bool r=false;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>a;
    for(int i=1;i<=a;i++){
    	int b;
		cin>>b;
		string y;
		cin>>y;
		for(int i=1;i<=b;i++){
			
			c+=y;
		//	cout<<c<<endl;
		}
	}int g=c.size();
	if(g%2==0){
		for(int i=0;i<=g/2-1;i++){
			d+=c[i];
		}for(int i=g-1;i>=g/2;i--){
			e+=c[i];
		}
	}else{
		for(int i=0;i<=(g-1)/2-1;i++){
			d+=c[i];
			
		}for(int i=g-1;i>(g-1)/2;i--){
			e+=c[i];
			
		}
	}
	if(g%2==0){
		for(int i=0;i<=g/2-1;i++){
			if(d[i]!=e[i]){
				sum++;
			}
		}
	}else{
		for(int i=0;i<=(g-1)/2;i++){
			if(d[i]!=e[i]){
				sum++;
			}
		}
	}cout<<sum;
	return 0;
} 
