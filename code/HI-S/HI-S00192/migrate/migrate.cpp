#include<bits/stdc++.h>
using namespace std;
bool is(vector<int> s,int a,int b,int q){
	if(s[b]-s[a]<=q){
		return 0;
	}
	for(int i=a+1;i<b;i++){
		if(s[a]-s[a-1]>b){
			return 0;
		}
	}
	return 1;
}

int find(vector<int> s,int a,int b,int q){
	for(int i=3;i<b-a;i++){
		bool f;
		
	}
}
int fun(vector<int> s,int a,int b,int q,int t){
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	int zzz,n;
	cin>>zzz>>n;
	while(n--){
		int a,b;
		cin>>a>>b;
		vector<int> s(a);
		for(int i=1;i<=a;i++){
			cin>>s[i-1];
		}
		for(int i=0;i<a-3;i++){
			for(int j=i+3;j<a;j++){
				if(is(s,i,j,b)){
					
					
					
					
					
				}
			}
		}
		
	}
	return 0;
} 
