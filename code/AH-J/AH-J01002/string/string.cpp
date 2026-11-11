#include <bits/stdc++.h>
using namespace std;
vector<char> temp;
vector<long long> an;
long long ans=0;
long long n,len;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		long long a;
		char chs;
		cin>>a>>chs;
		if(chs==temp[temp.size()-1]){
			an[temp.size()-1]+=a;
			continue;
		}
		temp.push_back(chs);
		an.push_back(a);
		len+=a;
	}
	long long s=0;
	for(long long i=0,j=an.size()-1;s<=len/2;){
		if(temp[i]!=temp[j]){
			if(an[i]>an[j] && an[j]+s<=len/2){
				s+=an[j];
				ans+=an[i];
				an[j]=0;
				an[i]-=an[j];
				j--;
			}
			else if(an[i]<=an[j] && an[i]+s<=len/2){
				s+=an[i];
				ans+=an[j];
				an[i]=0;
				an[j]-=an[i];
				i++;
				if(an[j]==0) j--;
			}
			else{
				ans+=len/2-s;
				break;
			}
		}
		else{
			if(an[i]>an[j]&& an[j]+s<=len/2){
				s+=an[j];
				an[i]-=an[j];
				an[j]=0;
				j--;
			}else if(an[j]>=an[i] && an[i]+s<=len/2){
				s+=an[i];
				an[j]-=an[i];
				an[i]=0;
				i++;
				if(an[j]==0) j--;
			}else{
				break;
			}
		}
	}	
	cout<<ans;
	return 0;		
}			
