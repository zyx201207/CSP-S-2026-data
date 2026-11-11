#include<bits/stdc++.h>
using namespace std;

int n;
unsigned long long strl,ll;
struct str_ing_n_char{
	unsigned long long ai;
	char chi;
}a[200020];

              
int main(){
//	freopen("string.in","w",stdout);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	
	int l=1;
	for(int i=1;i<=n;i++,l++){
		cin>>a[l].ai>>a[l].chi;
		strl+=a[l].ai;
		if(a[l].chi==a[l-1].chi){
			a[l-1].ai+=a[l].ai;
			l--;
		}
	}
	if(strl%2==1){
		unsigned long long sum=0;
		for(int i=1;i<l;i++){
			sum+=a[i].ai;
			if(sum>strl/2){
				a[i].ai-=1;
				break;
			}
		}
	}
	
	int i=1,j=l-1;
	if(i==j){
		strl=1;
	}
	while(i<j){
		if(a[i].chi==a[j].chi){
			if(a[i].ai==a[j].ai){
				i++;
				j--;
			}
			else{
				if(a[i].ai>a[j].ai){
					a[i].ai-=a[j].ai;
					j--;
				}
				else if(a[i].ai<a[j].ai){
					a[j].ai-=a[i].ai;
					i++;
				}
			}
		}
		else if(a[i].chi!=a[j].chi){
			if(a[i].ai==a[j].ai){
				ll+=a[i].ai;
				i++;
				j--;
			}
			else if(a[i].ai>a[j].ai){
				a[i].ai-=a[j].ai;
				ll+=a[j].ai;
				j--;
			}
			else if(a[i].ai<a[j].ai){
				a[j].ai-=a[i].ai;
				ll+=a[i].ai;
				i++;
			}
		}
	}
	
//	cout<<strl<<" "<<l<<" ";
	
//	for(int i=1;i<l;i++){
//		cout<<a[i].ai<<" ";
//	}
	
	cout<<ll;
	return 0;           
}