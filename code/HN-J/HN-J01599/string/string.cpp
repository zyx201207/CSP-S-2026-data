#include<bits/stdc++.h>
using namespace std;
const int NN=2e5+10;
struct TT{
	char ch;
	int a;
};
int n;
TT v[NN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>v[i].a>>v[i].ch;
	}
	long long res=0;
	int i=1,j=n;
	while(i<j){
		if(v[i].ch==v[j].ch){
			if(v[i].a>v[j].a){
				v[i].a-=v[j].a;
				j--;
			}
			else if(v[i].a<v[j].a){
				v[j].a-=v[i].a;
				i++;
			}
			else {
				j--;
				i++;
			}
		}
		else{
			if(v[i].a>v[j].a){
				res+=v[j].a;
				v[i].a-=v[j].a;
				j--;
			}
			else if(v[i].a<v[j].a){
				res+=v[i].a;
				v[j].a-=v[i].a;
				i++;
			}
			else {
				res+=v[i].a;
				j--;
				i++;
			}
		}
	}
	cout<<res;
	return 0;
} 
