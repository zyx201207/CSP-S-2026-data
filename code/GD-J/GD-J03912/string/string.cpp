#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 205000;
ll a[N]={}, ch[N]={};
char c;
ll n=0,m=0,i=0,j=0,k=0,tot=0, x=0, add=0, jian,ans = 0, t, cc;
pair<int,char>hd,tl;
//
//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//int n, m, i, j, k, a[N];
deque<pair<int, char> > q;
int main()
{
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	cin >> n;
	if (n == 1)
	{
		cout << 0;
		fclose(stdin);
		fclose(stdout); 
		return 0;
	}
	for (i=1; i<=n; i++)
	{
		cin >>a[i];
		cin >> c;
		ch[i] = c - 'a';
		tot = tot + a[i];
		q.push_back(make_pair(a[i],ch[i]));
	}
	while (!q.empty())
	{
		hd=q.front();
		tl=q.back();
		if (!q.empty())q.pop_front();
		if (!q.empty())q.pop_back();
		t = min(hd.first, tl.first);
		hd.first -= t;
		tl.first -= t;
		if (hd.second != tl.second) ans += t;
		if (hd.first != 0)
		{
			q.push_front(hd);
		}
		if (tl.first!=0)
		{
			q.push_back(tl);
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

//stack<ll>st; 
//stack<ll>zf;
//int main()
//{

//	cin >> n;
//	for (i=1; i<=n; i++)
//	{
//		cin >>a[i];
//		cin >> c;
//		ch[i] = c - 'a';
//		tot = tot + a[i];
//	}
////	for (i=1; i<=n ;i++)
////	{
////		cout << a[i ] << " " << ch[i] << endl;
////	}
////	cout << tot << endl;
//	k = tot / 2;
//	x = 0;
//	for (i=1; i<=n; i++)
//	{
////		cout << x <<" " << a[i]<< endl;
//		if (x <= k && x+a[i] <= k)
//		{
//			x += a[i];
//			st.push(a[i]);
//			zf.push(ch[i]);
//		}else if (x <= k && x+a[i] > k)
//		{
//			add = k-x;
//			x=k;
//			a[i] -= add;
//			st.push(add);
//			zf.push(ch[i]);
//			if (tot %2 == 1 && a[i] > 0)
//			{
//				a[i] --;
//				x ++;
//			}
//			while (a[i] > 0)
//			{
//				t = st.top();
//				cc = zf.top();
//				st.pop();zf.pop();
//				jian = min(t, a[i]);
//				a[i] -= jian;
//				t -= jian;
//				x += jian;
//				if (cc != ch[i])
//				{
//					ans += jian;
//				}
//				if (t != 0)
//				{
//					st.push(t);zf.push(cc);
//				}
//			}
//		}else{
//			while (a[i] > 0)
//			{
//				t = st.top();
//				cc = zf.top();
//				st.pop();zf.pop();
//				jian = min(t, a[i]);
//				a[i] -= jian;
//				t -= jian;
//				x += jian;
//				if (cc != ch[i])
//				{
//					ans += jian;
//				}
//				if (t != 0)
//				{
//					st.push(t);zf.push(c);
//				}
//			}
//		}
//	}
//	cout << ans;
//	return 0;
//}
//
////




