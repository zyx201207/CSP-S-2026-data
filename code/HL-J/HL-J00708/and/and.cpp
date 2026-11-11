#include<bits/stdc++.h>
using namespace std;
bool waibi(int a,int b){
	return a>b;
}
vector <long long> w;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	vector <long long> c(a);
	for(long long i=0;i<a;i++){
		cin>>c[i];
    }
	if(b==2){
		for(int i=0;i<a;i++){
			for(int x=i+1;x<a;x++){
				w.push_back(c[i]&c[x]);
			}
		}
		sort(w.begin(),w.end(),waibi);
		cout<<w[0];
	}
	if(b==3){
		
		for(int i=0;i<a;i++){
			for(int x=i+1;x<a;x++){
				for(int y=x+1;y<a;y++){
					w.push_back(c[i]&c[x]&c[y]);
				}
			}
		}
		sort(w.begin(),w.end(),waibi);
		cout<<w[0];
	}
	if(b==4){
		for(int i=0;i<a;i++){
			for(int x=i+1;x<a;x++){
				for(int y=x+1;y<a;y++){
					for(int z=y+1;z<a;z++){
						w.push_back(c[i]&c[x]&c[y]&c[z]);
					}
				}
			}
		}
		sort(w.begin(),w.end(),waibi);
		cout<<w[0];
	}
	if(b==5){
		
		for(int i=0;i<a;i++){
			for(int x=i+1;x<a;x++){
				for(int y=x+1;y<a;y++){
					for(int z=y+1;z<a;z++){
						for(int k=z+1;k<a;k++){
							w.push_back(c[i]&c[x]&c[y]&c[z]&c[k]);
						}
					}
				}
			}
		}
		sort(w.begin(),w.end(),waibi);
		cout<<w[0];
	}
	
	
	
	
    return 0;	
}