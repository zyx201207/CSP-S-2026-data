#include<iostream>
#include<vector>
using namespace std;
#define int long long
struct st_part{
	int start,end;
	char c;
};
vector<st_part> raw_parts;
int abs(int x){
	return max(x,-x);
}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,curr_place=0;
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		int a;
		char c;
		scanf("%lld %c",&a,&c);
		st_part this_part;
		
		this_part={curr_place,curr_place+a,c};
		curr_place+=a;
		raw_parts.push_back(this_part);
	}
	int i=0,ans=0;
	
	while(i<n){
		
		int rt=curr_place-raw_parts[i].start;
		int lt=curr_place-raw_parts[i].end;
		if(lt<=curr_place/2-1){
			break;
		}
		int j_place=n-1;
		for(;;){
			if(raw_parts[j_place].end<=rt||raw_parts[j_place].start>=lt){
				if(raw_parts[j_place].c!=raw_parts[i].c){
					if(raw_parts[j_place].end<=rt&&raw_parts[j_place].start>=lt){
						ans+=::abs(raw_parts[j_place].end-raw_parts[j_place].start);
					}else if(raw_parts[j_place].start<=lt){
						ans+=raw_parts[j_place].end-lt;
					}else{
						ans+=::abs(rt-raw_parts[j_place].start);
					}
				}
				
			}
			if(raw_parts[j_place].end<lt){
				break;
			}
			j_place--;
		}
		i++;
		
	}
	cout<<ans;
}
