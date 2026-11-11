#include<bits/stdc++.h>
#define long long int
using namespace std;

bool cs0=0;

int cs(int cs1,string s){
	if(cs0==0){
		cout<<s<<":"<<cs1<<endl;
	}
	return cs1;

}
//±äÁ¿
struct csa_me{
	int a;
	char b;	
}sz[200005];
int n;
int a1=1;
int b1;
int all_num_it=0;
signed main(){
	if(cs0==0){
		ios::sync_with_stdio(0);
		cin.tie(0); 
		freopen("string.in","r",stdin);
		freopen("string.out","w",stdout);
	}
	
	//´úÂë 
	cin>>n;
	b1=n;
	for(int i=1;i<=n;i++){
		cin>>sz[i].a>>sz[i].b;
	}

	while(a1<b1){
			if(sz[a1].b==sz[b1].b){
			if(sz[a1].a==sz[b1].a){
				sz[a1].a=0;
				sz[b1].a=0;
				
				a1++;
				b1--;
			}else if(sz[a1].a>sz[b1].a){
				sz[a1].a-=sz[b1].a;
				b1--;
			}else if(sz[a1].a<sz[b1].a){
				sz[b1].a-=sz[a1].a;
				a1++;
			} 
		}else{
			if(sz[a1].a==sz[b1].a){
				all_num_it+=sz[a1].a;
				sz[a1].a=0;
				sz[b1].a=0;
				a1++;
				b1--;
			}else if(sz[a1].a>sz[b1].a){
				all_num_it+=sz[b1].a;
				sz[a1].a-=sz[b1].a;
				b1--;
			}else if(sz[a1].a<sz[b1].a){
				all_num_it+=sz[a1].a;
				sz[b1].a-=sz[a1].a;
				a1++;
			} 
		}
	}

	
	cout<<all_num_it;
		
	
	
	return 0; 
} 
