#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
using ll=long long;
int n;
ll m,mid,mid1,mid2,maxn=1;
inline ll labs(ll num){
    return (num<0)?-num:num;
}

ll midCnt(vector<ll>::iterator it1,vector<ll>::iterator it2,ll md){
	ll cnt=0;
	for(auto bgn=it1;bgn!=it2;bgn++){
		if(*bgn==md)cnt++;
	}
	return cnt;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	vector<ll> v(n);
	for(auto &a:v){cin>>a;}
	sort(v.begin(),v.end());
	if(n&1){
		mid=v.at(n/2);
		ll /*cnt=0,*/tmp=m;
		vector<ll> vt1(v.begin(),v.end());
		for(int i=0;i<n;i++){
			if(labs(mid-vt1.at(i))<=tmp){
				if(i!=n/2){
					tmp-=labs(mid-vt1.at(i));
					vt1.at(i)=mid;
	//				cout<<"tmp"<<tmp<<endl; 
	//				cnt++;
	//				cout<<"cnt"<<cnt<<endl;
				}	
				 
			}else break;
		}
		maxn=max(maxn,midCnt(vt1.begin(),vt1.end(),mid));
//		maxn=max(maxn,cnt);
//		cout<<"maxn"<<maxn<<endl; 
		/*cnt=0,*/tmp=m;
		vector<ll> vt2(v.begin(),v.end());
		for(int i=n-1;i>=0;i--){
			if(labs(mid-vt2.at(i))<=tmp){
				if(i!=n/2){
					tmp-=labs(mid-vt2.at(i));
					vt2.at(i)=mid;
	//				cout<<"tmp"<<tmp<<endl; 
	//				cnt++;
	//				cout<<"cnt"<<cnt<<endl; 
				}
				
			}else break;
		}
		maxn=max(maxn,midCnt(vt2.begin(),vt2.end(),mid));
//		maxn=max(maxn,cnt);
//		cout<<"maxn"<<maxn<<endl; 
	}else{
		mid1=v.at(n/2-1),mid2=v.at(n/2);
//		cout<<"mid1:"<<mid1<<endl; 
//		cout<<"mid2:"<<mid2<<endl; 
//		cout<<"first:"<<v.at(0)<<endl;
//		cout<<"last:"<<v.at(v.size()-1)<<endl;
		ll /*cnt=0,*/tmp=m;
		vector<ll> vt1(v.begin(),v.end());
		for(int i=0;i<n;i++){
		//	cout<<"is_smaller:"<<(labs(mid1-vt1.at(i))<=tmp&&i!=n/2-1)<<endl;
			if(labs(mid1-vt1.at(i))<=tmp){
				if(i!=n/2-1){
				//  cout<<"labs:"<<((mid1-vt1.at(i)<0)?(-(mid1-vt1.at(i))):(mid1-vt1.at(i)))<<endl;
				//	cout<<"labs:"<<vt1.at(i)<<endl;
					tmp-=labs(mid1-vt1.at(i));
//					cout<<"vt.at(i):"<<vt1.at(i)<<endl;
				    vt1.at(i)=mid1;
//					cout<<"tmp"<<tmp<<endl; 
	//				cnt++;
	//				cout<<"cnt"<<cnt<<endl; 
				}
		    
			}else break;
		}
	//	for(auto &a:vt1)cout<<a<<endl; 
		maxn=max(maxn,midCnt(vt1.begin(),vt1.end(),mid1));
//		maxn=max(maxn,cnt);
//		cout<<"maxn"<<maxn<<endl; 
		/*cnt=0,*/tmp=m;
		vector<ll> vt2(v.begin(),v.end());
		for(int i=n-1;i>=0;i--){
			if(labs(mid1-vt2.at(i))<=tmp){
				if(i!=n/2-1){
					tmp-=labs(mid1-vt2.at(i));
					vt2.at(i)=mid1;
	//				cout<<"tmp"<<tmp<<endl; 
	//				cnt++;
	//				cout<<"cnt"<<cnt<<endl; 
				}

			}else break;
		}
		maxn=max(maxn,midCnt(vt2.begin(),vt2.end(),mid1));
//		maxn=max(maxn,cnt);
//		cout<<"maxn"<<maxn<<endl; 
	    /*cnt=0,*/tmp=m;
		vector<ll> vt3(v.begin(),v.end());
		for(int i=0;i<n;i++){
			if(labs(mid2-vt3.at(i))<=tmp){
				if(i!=n/2){
					tmp-=labs(mid2-vt3.at(i));
					vt3.at(i)=mid2;
	//				cout<<"tmp"<<tmp<<endl; 
	//				cnt++;
	//				cout<<"cnt"<<cnt<<endl; 
				}
			
			}else break;
		}
		maxn=max(maxn,midCnt(vt3.begin(),vt3.end(),mid2));
//		maxn=max(maxn,cnt);
//		cout<<"maxn"<<maxn<<endl; 
		/*cnt=0,*/tmp=m;
		vector<ll> vt4(v.begin(),v.end());
		for(int i=n-1;i>=0;i--){
			if(labs(mid2-vt4.at(i))<=tmp){
				if(i!=n/2){
					tmp-=labs(mid2-vt4.at(i));
					vt4.at(i)=mid2;
	//			    cout<<"tmp"<<tmp<<endl; 
	//				cnt++;
	//				cout<<"cnt"<<cnt<<endl; 
				}
			}else break;
		}
		maxn=max(maxn,midCnt(vt4.begin(),vt4.end(),mid2));
//		maxn=max(maxn,cnt);
//		cout<<"maxn"<<maxn<<endl; 
	}
	cout<<maxn;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
