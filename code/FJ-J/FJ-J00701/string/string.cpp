#include<bits/stdc++.h>
using namespace std;
struct s{
	long long a;
	char c;
}sl[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0,zh=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>sl[i].a>>sl[i].c;	
		zh+=sl[i].a;
    }
    if(zh%2==1){
    	sum-=1;
	}
    int l=1,r=n;
    while(l<r){
    	
    	while(sl[l].a==0){
    		l++;
		}
		while(sl[r].a==0){
			r--;
		}
		if(sl[l].a==sl[r].a&&sl[l].c!=sl[r].c){
			sum+=sl[l].a;
			l+=1;
		    r-=1;
			continue;
		}
		else if(sl[l].c==sl[r].c){
			if(sl[l].a>sl[r].a){
				int j=sl[l].a-sl[r].a;
				int k=r-1;
				while(j){
					if(j>=sl[k].a){
						sum+=sl[k].a;
						j-=sl[k].a;
						sl[k].a=0;
						k--;
					}
					else{
						sum+=j;
						sl[k].a-=j;
						j=0;
					}
				}
			}
			else if(sl[l].a==sl[r].a){
				continue;
			}
			else{
				int j=sl[r].a-sl[l].a;
				int k=l+1;
				while(j){
					if(j>=sl[k].a){
						sum+=sl[k].a;
						j-=sl[k].a;
						sl[k].a=0;
						k++;
					}
					else{
						sum+=j;
						sl[k].a-=j;
						j=0;
					}
				}
			}
		}
		else if(sl[l].c!=sl[r].c){
			if(sl[l].a>sl[r].a){
				sum+=sl[r].a;
				int j=sl[l].a-sl[r].a;
				int k=r-1;
				while(j){
					if(j>=sl[k].a){
						sum+=sl[k].a;
						j-=sl[k].a;
						sl[k].a=0;
						k--;
					}
					else{
						sum+=j;
						sl[k].a-=j;
						j=0;
					}
				}
			}
			else{
				sum+=sl[l].a; 
				int j=sl[r].a-sl[l].a;
				int k=l+1;
				while(j){
					if(j>=sl[k].a){
						sum+=sl[k].a;
						j-=sl[k].a;
						sl[k].a=0;
						k++;
					}
					else{
						sum+=j;
						sl[k].a-=j;
						j=0;
					}
				}
			}
		}
		l+=1;
		r-=1;
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<sl[i].a<<sl[i].c<<endl;
	}
	cout<<sum;
	
} 
