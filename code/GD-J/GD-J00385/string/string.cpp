#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt;
string s1,s2;
struct ab{
	long long a;
	char c;
};
ab hws[50];
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>hws[i].a>>hws[i].c;
	}
	int i=1;
	int j=n;
	while(i<j){
		if(hws[i].a>hws[j].a){
			if(hws[i].c!=hws[j].c){
				cnt+=(hws[j].a);
			}
			hws[i].a=hws[i].a-hws[j].a;
			j--;
		}
		if(hws[i].a<hws[j].a){
			if(hws[i].c!=hws[j].c){
				cnt+=(hws[i].a);
			}
			hws[j].a=hws[j].a-hws[i].a;
			i++;
		}
		if(hws[i].a==hws[j].a){
			if(hws[i].c!=hws[j].c){
				cnt+=(hws[j].a);
			}
			j--;
			i++;
		}
	}
	cout << cnt;
	
	return 0;
} 
