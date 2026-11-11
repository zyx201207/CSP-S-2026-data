#include<bits/stdc++.h>
using namespace std;
const int maxn=2*1e5;
long long n,ans=0;
struct node{
	long long a;
	char c;
}s[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	vector<pair<long long,char>>pre_s;
	vector<pair<long long,char>>pre_e;
	int left=1,right=n;
	while(left<=right){
			char sc=s[left].c,ec=s[right].c;
			long long sa=s[left].a,ea=s[right].a;
			if(!pre_s.empty()){
				auto it=pre_s.front();
				pre_s.pop_back();
				long long pre_s_a=it.first;
				char pre_s_c=it.second;
				if(pre_s_c==ec){
					if(pre_s_a>ea){
						pre_s.push_back({pre_s_a-ea,pre_s_c});
						ea-=pre_s_a;
					}
					else{
						ea-=pre_s_a;
					}
				}
				else{
					if(pre_s_a>ea){
						ans+=ea;
						pre_s.push_back({pre_s_a-ea,pre_s_c});
						ea=0;
					}
					else{
						ans+=pre_s_a;
						ea-=pre_s_a;
					}
				}
			}
			if(!pre_e.empty()){
				auto it=pre_e.front();
				pre_e.pop_back();
				long long pre_e_a=it.first;
				char pre_e_c=it.second;
				if(pre_e_c==sc){
					if(pre_e_a>sa){
						pre_e.push_back({pre_e_a-sa,pre_e_c});
						sa=0;
					}
					else{
						sa-=pre_e_a;
					}
				}
				else{
					if(pre_e_a>sa){
						ans+=sa;
						pre_e.push_back({pre_e_a-sa,pre_e_c});
						sa=0;
					}
					else{
						ans+=pre_e_a;
						ea-=pre_e_a;
					}
				}
			}
			if(sc==ec){
				if(sa>ea){
					pre_s.push_back({sa-ea,sc});
				}
				else if(ea>sa){
					pre_e.push_back({ea-sa,ec});
				}
			}
			else{
				if(sa>ea){
					pre_s.push_back({sa-ea,sc});
					ans+=ea;
				}
				else if(ea>sa){
					pre_e.push_back({ea-sa,ec});
					ans+=sa;
				}
				else if(ea==sa){
					ans+=sa;
				}
			}
		left++;
		right--;
	}
	cout<<ans;
	return 0;
}
