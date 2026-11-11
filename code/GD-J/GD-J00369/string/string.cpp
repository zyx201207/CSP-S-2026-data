#include <bits/stdc++.h>
using namespace std;

long long n;

struct node1{
	long long lth;
	char c;
};

struct node2{
	long long l,r;
	char c;
};

node1 a[333333];
node2 q[333333];
node2 h[333333];

bool sb(node2 a,node2 b){
	return a.r<b.r;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	if(n==1){
		cout << 0;
		return 0;
	}
	long long sum = 0;
	for (long long i = 1;i <= n;i++){
		cin >> a[i].lth >> a[i].c;
		sum+=a[i].lth;
	}
	if(sum%2==1){
		long long k = sum/2+1;
		long long cnt = 0;
		for (long long i = 1;i <= n;i++){
			cnt+=a[i].lth;
			if(cnt>=k){
				a[i].lth--;
				break;
			}
		}sum--;
	}
	q[0].l=0,q[0].r=0;
	for (long long i = 1;i <= n;i++){
		q[i].l=q[i-1].r+1;
		q[i].r=q[i].l+(a[i].lth-1);
		q[i].c=a[i].c;
	}
	long long k = sum/2;
	long long x = 0;
	long long cnt = 0;
	x = k;
	for (long long i = 1;i <= n;i++){
		if((q[i].l>=k&&q[i].r >= k)||(q[i].l<=k&&q[i].r>=k)){
			cnt++;
			if(cnt==1){
//				cout << q[i].l << " " << q[i].r;                            
//				cout<< endl;
				
				if(q[i].r!=k){
					h[cnt].r = k;
					h[cnt].l = k-(q[i].r-k)+1;
					h[cnt].c=q[i].c;
				}
				if(q[i].r==k){
					h[cnt].r = k;
					h[cnt].l = k-(q[i+1].r-k)+1;
					h[cnt].c=q[i+1].c;
					i++;
				}
				q[i].r = k;
			}if(cnt>1){
				
			h[cnt].r = k-(q[i].l-k)+1;
			h[cnt].l = k-(q[i].r-k)+1;
			h[cnt].c=q[i].c;
			}
		}
	}
	
	
	
	long long ql,hl;
	for (long long i = 1;i <= n;i++){
		if(q[i].r==k){
			ql = i;
			break;
		}
	}for (long long i = 1;i <= n;i++){
		if(h[i].l == 0){
			hl = i-1;
			break;
		}
	}
	sort(h+1,h+hl+1,sb);
	long long ans = 0;
	long long qx = 1,hx = 1;
//	cout << "h0:" << h[1].l << " " << h[1].r;
//	cout << "hl:" << hl;
	while(hx<=hl||qx<=ql){
		if(q[qx].r < h[hx].r){
			ans += q[qx].r-max(q[qx].l-1,h[hx].l-1);
			if(q[qx].c==h[hx].c){
				ans -= q[qx].r-max(q[qx].l-1,h[hx].l-1);
			}
			qx++;
//			cout << 1 << endl;
		}else if(q[qx].r > h[hx].r){
			ans += h[hx].r - max(q[qx].l-1,h[hx].l-1);
			if(q[qx].c==h[hx].c){
				ans -= h[hx].r - max(q[qx].l-1,h[hx].l-1);
			}
			hx++;
//			cout << 2 << endl;
		}else if(q[qx].r==h[hx].r){
			ans += h[hx].r-max(h[hx].l-1,q[qx].l-1);
//			cout << "h[hx].r:"<<h[hx].r << "h[hx].c:" << h[hx].c;
//			cout << "q[qx].r:"<<q[qx].r << "q[qx].c:" << q[qx].c;
			if(q[qx].c==h[hx].c){
				ans -= h[hx].r-max(h[hx].l-1,q[qx].l-1);
			}
			hx++,qx++;
//			cout << 3 << endl;
		}
//		cout << "ans:" << ans << endl;
	}
	
	cout << ans;
	
//	for (int i = 1;i <= ql;i++){
//		cout << q[i].c;
//	}
	/*
	
	for (long long i = 1;i <= n;i++){
		cout << q[i].l << " " << q[i].r << endl;
	}for (long long i = 1;i <= n;i++){
		cout << h[i].l << " " << h[i].r << endl;
	}cout << "k" << ":" << k;
	
	*/
	/*
4
4 c
9 a
10 b
8 a



2
2 a
3 a


6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b


	*/
	
	return 0;
} 
