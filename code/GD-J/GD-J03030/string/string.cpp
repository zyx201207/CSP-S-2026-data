#include<bits/stdc++.h>
using namespace std;
long long n,a,cnt,len;
char c;
struct node{
	long long a;
	char c;
};
vector<node> s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		long long u;
		char v;
		cin>>u>>v;
		s.push_back({u,v});
	}
	if(s.size()%2==0){
		len=s.size()/2;
	}
	else{
		len=s.size()/2+1;
	}
	for(int i=0,h=s.size()-1;i<=len+1;i++,h--){
		if(s[i].c==s[h].c){
			if(s[h].a>s[i].a){
				s[h].a-=s[i].a;
				s[i].a=0;
			}
			else{
				s[i].a-=s[h].a;
				s[h].a=0;
			}
		}
		else{
			if(s[h].a>s[i].a){
				cnt+=s[i].a;
				s[i].c=s[h].c;
				s[h].a-=s[i].a;
				s[i].a=0;
			}
			else{
				cnt+=s[h].a;
				s[h].c=s[i].c;
				s[i].a-=s[h].a;
				s[h].a=0;
			}	
		}
		
		if(s[i].a>0){
			i--;
		}
		if(s[h].a>0){
			h++;
		}
	}
	
	cout<<cnt<<endl;
	
	
	
	
	
	return 0;
	
	
//	for(int i=0;i<s.size();i++){
//		if(s[i].c!=s[s.size()-i-1].c){
//			cnt+=min(s[i].a,s[s.size()-i-1].a);
//			if(s[i].a<s[s.size()-i-1].a){
//				s[i].c=s[s.size()-i-1].c;
//				s[i].a=0;
//				s[s.size()-i-1]-=s[i].a;
//			}
//			else{
//				s[s.size()-i-1].c=s[i].c;
//			}
//		}
//	}
}
