#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int add_all=0,add=0;
	vector<pair<int,char> >in(n);
	for(int i=0;i<n;i++){
		cin>>in[i].first>>in[i].second;
		/*if(i!=0&&in[i].second==in[i-1].second){
			in[i-1].first+=in[i].first;
		//???	
		}*/
		add_all+=in[i].first;
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	int mid=0;
	for(int i=0;i<n;i++){
		add+=in[i].first;
		if(add>add_all/2){
//			cout<<i<<" ";//??
			//!!
			mid=i;
			break;
		}
	}
	add-=in[mid].first;//Ah! I put it in the wrong place!
	int out=0;
	int i=mid,j=mid;
	int i_now,j_now;//that's important!!
	i_now=add_all/2-add;//1???//if 1,then it is mid-1.
	j_now=in[mid].first-i_now;//if 1,it must be mid+1.
	if(add_all%2==1){
		j_now--;//?!?!?!
	}
	/*{
		//debug
		cout<<add_all<<" "<<add<<" ";
		cout<<mid<<" "<<i_now<<" "<<j_now<<"\n";
	}*/
	int temp;
	{
		//?
		//two_pointers!!!
		while(i>=0&&j<n){
			if(i_now==0){
				i--;
				if(i<0){
					cout<<out;
					return 0;
				}
				i_now=in[i].first;
			}
			if(j_now==0){
				j++;
				if(j>=n){
					cout<<out;
					return 0;
				}
				j_now=in[j].first;
			}
			temp=min(i_now,j_now);
			if(in[i].second!=in[j].second)out+=temp;//wrong?
			//delete it.
			i_now-=temp;
			j_now-=temp;
				
			/*{
				cout<<i<<"?"<<j<<"\n";
				cout<<i_now<<"."<<j_now<<"\n";
			}*/
		}
	}
	cout<<out;
	return 0;
}
//I done it!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
