#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int n,k;
map<int,int>b;
	
map<int,int>a;

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		//cout<<i<<' ';
		b[tmp]++;
	}
	
	for(auto it:b){
		int tmp=it.first;
		
		for(int i=0;tmp;i++){
			if(tmp%2)a[tmp%2<<i]+=it.second;
			tmp/=2;
		}
	}
	
	int h=0;
		
	int flag=0;
	for(auto it:a){
		if(it.second>=k&&it.first>h){
			h=it.first;
			flag=1;
		}
		//cout<<it.first<<' '<<it.second<<'\n';
	}
	//cout<<'\n';
	
	while(flag){
		//cout<<h<<"-------"<<'\n';
		for(auto it:a){
			a[it.first]=0;
		}
		
		for(auto it:b){
			if((h&it.first)==0)continue;
			int tmp=it.first;
			
			for(int i=0;tmp;i++){
				if(tmp%2){
					if(h&(tmp%2<<i))break;
					a[tmp%2<<i]+=it.second;
				}
				tmp/=2;
			}
		}
		int g=0;
		
		flag=0;
		for(auto it:a){
			if(it.second>=k&&it.first>g){
				g=it.first;
				flag=1;
			}
			
			//cout<<it.first<<' '<<it.second<<'\n';
		}
		h|=g;
		
		//cout<<'\n';
	}
	cout<<h<<'\n';	
	return 0;
}
