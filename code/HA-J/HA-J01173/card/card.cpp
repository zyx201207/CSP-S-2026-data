#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int s[N];
bool ss[N];
stack<int> sk;
map <int,int>p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>s[i];
    }
    int h=1;
    while(h<=n){
    	for(int i=1;i<=m;i++){
    		ss[i]=false;
    	}
    	for(int i=h;i<=n;i++){
    		if(!ss[s[i]]){
    			sk.push(s[i]);
    			ss[s[i]]=true;
    		}else{
    			while(sk.top()!=s[i]){
    				ss[sk.top()]=false;
					sk.pop();
    			}
    		}
    	}
    	while(!sk.empty()){
    		p[sk.top()]++;
    		sk.pop();
    	}
    	h++;
    }
    for(int i=1;i<=m;i++){
    	cout<<p[i]<<" ";
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
