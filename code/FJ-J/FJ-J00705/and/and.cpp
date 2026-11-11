#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Please return
#define AC 0
#define fxa(x,n) for (int x=0;x<n;x++)
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,a[1145140],ans,maxx=-1;
    cin>>n>>m;
    for (int i=0;i<n;i++)cin>>a[i];
    if (m==1){
    	sort(a,a+n);
    	maxx=a[0];
	}
    else if (m==2){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            ans=a[i]&a[j];
            maxx=max(maxx,ans);
        }
    }}
    else if (m==3){
    	for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            for (int k=0;k<n;k++){
            	ans=a[i]&a[j]&a[k];
            maxx=max(maxx,ans);
            }
        }
    }}
    else if (m==4){
    	fxa(b,n) fxa (c,n) fxa(d,n) fxa(e,n)ans=a[c]&a[d]&a[e]&a[e],maxx=max(maxx,ans);
	}
	else if (m==5){fxa(b,n) fxa (c,n) fxa(d,n) fxa(e,n) fxa(f,n)ans=a[f]&a[c]&a[d]&a[e]&a[b],maxx=max(maxx,ans);}
	else if (m==6){fxa(b,n) fxa (c,n) fxa(d,n) fxa(e,n) fxa(f,n) fxa(g,n)ans=a[g]&a[f]&a[c]&a[d]&a[e]&a[b],maxx=max(maxx,ans);}
	else if (m==7){fxa(b,n) fxa (c,n) fxa(d,n) fxa(e,n) fxa(f,n) fxa(g,n) fxa(h,n)ans=a[h]&a[g]&a[f]&a[c]&a[d]&a[e]&a[b],maxx=max(maxx,ans);}
    else if (m==8){fxa(b,n) fxa (c,n) fxa(d,n) fxa(e,n) fxa(f,n) fxa(g,n) fxa(i,n) fxa(h,n)ans=a[i]&a[h]&a[g]&a[f]&a[c]&a[d]&a[e]&a[b],maxx=max(maxx,ans);}
    else if (m==9){ fxa (b,n) fxa (c,n) fxa (d,n) fxa (e,n) fxa (f,n) fxa (g,n) fxa (h,n) fxa (i,n) fxa (j,n)ans=a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j],maxx=max(maxx,ans);}
else if (m==10){ fxa (b,n) fxa (c,n) fxa (d,n) fxa (e,n) fxa (f,n) fxa (g,n) fxa (h,n) fxa (i,n) fxa (j,n) fxa (k,n)ans=a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k],maxx=max(maxx,ans);}
else if (m==11){ fxa (b,n) fxa (c,n) fxa (d,n) fxa (e,n) fxa (f,n) fxa (g,n) fxa (h,n) fxa (i,n) fxa (j,n) fxa (k,n) fxa (l,n)ans=a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l],maxx=max(maxx,ans);}
else if (m==12){ fxa (b,n) fxa (c,n) fxa (d,n) fxa (e,n) fxa (f,n) fxa (g,n) fxa (h,n) fxa (i,n) fxa (j,n) fxa (k,n) fxa (l,n) fxa (m,n)ans=a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m],maxx=max(maxx,ans);}
else if (m==13){ fxa (b,n) fxa (c,n) fxa (d,n) fxa (e,n) fxa (f,n) fxa (g,n) fxa (h,n) fxa (i,n) fxa (j,n) fxa (k,n) fxa (l,n) fxa (m,n) fxa (n,n)ans=a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m]&a[n],maxx=max(maxx,ans);}
else if (m==14){ fxa (b,n) fxa (c,n) fxa (d,n) fxa (e,n) fxa (f,n) fxa (g,n) fxa (h,n) fxa (i,n) fxa (j,n) fxa (k,n) fxa (l,n) fxa (m,n) fxa (n,n) fxa (o,n)ans=a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m]&a[n]&a[o],maxx=max(maxx,ans);}
else if (m==15){ fxa (b,n) fxa (c,n) fxa (d,n) fxa (e,n) fxa (f,n) fxa (g,n) fxa (h,n) fxa (i,n) fxa (j,n) fxa (k,n) fxa (l,n) fxa (m,n) fxa (n,n) fxa (o,n) fxa (p,n)ans=a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m]&a[n]&a[o]&a[p],maxx=max(maxx,ans);}
else if (m==16){ fxa (b,n) fxa (c,n) fxa (d,n) fxa (e,n) fxa (f,n) fxa (g,n) fxa (h,n) fxa (i,n) fxa (j,n) fxa (k,n) fxa (l,n) fxa (m,n) fxa (n,n) fxa (o,n) fxa (p,n) fxa (q,n)ans=a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m]&a[n]&a[o]&a[p]&a[q],maxx=max(maxx,ans);}
else if (m==17){ fxa (b,n) fxa (c,n) fxa (d,n) fxa (e,n) fxa (f,n) fxa (g,n) fxa (h,n) fxa (i,n) fxa (j,n) fxa (k,n) fxa (l,n) fxa (m,n) fxa (n,n) fxa (o,n) fxa (p,n) fxa (q,n) fxa (r,n)ans=a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m]&a[n]&a[o]&a[p]&a[q]&a[r],maxx=max(maxx,ans);}
else if (m==18){ fxa (b,n) fxa (c,n) fxa (d,n) fxa (e,n) fxa (f,n) fxa (g,n) fxa (h,n) fxa (i,n) fxa (j,n) fxa (k,n) fxa (l,n) fxa (m,n) fxa (n,n) fxa (o,n) fxa (p,n) fxa (q,n) fxa (r,n) fxa (s,n)ans=a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m]&a[n]&a[o]&a[p]&a[q]&a[r]&a[s],maxx=max(maxx,ans);}
else if (m==19){ fxa (b,n) fxa (c,n) fxa (d,n) fxa (e,n) fxa (f,n) fxa (g,n) fxa (h,n) fxa (i,n) fxa (j,n) fxa (k,n) fxa (l,n) fxa (m,n) fxa (n,n) fxa (o,n) fxa (p,n) fxa (q,n) fxa (r,n) fxa (s,n) fxa (t,n)ans=a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m]&a[n]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t],maxx=max(maxx,ans);}
else if (m==20){ fxa (b,n) fxa (c,n) fxa (d,n) fxa (e,n) fxa (f,n) fxa (g,n) fxa (h,n) fxa (i,n) fxa (j,n) fxa (k,n) fxa (l,n) fxa (m,n) fxa (n,n) fxa (o,n) fxa (p,n) fxa (q,n) fxa (r,n) fxa (s,n) fxa (t,n) fxa (u,n)ans=a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m]&a[n]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u],maxx=max(maxx,ans);}
else if (m==21){ fxa (b,n) fxa (c,n) fxa (d,n) fxa (e,n) fxa (f,n) fxa (g,n) fxa (h,n) fxa (i,n) fxa (j,n) fxa (k,n) fxa (l,n) fxa (m,n) fxa (n,n) fxa (o,n) fxa (p,n) fxa (q,n) fxa (r,n) fxa (s,n) fxa (t,n) fxa (u,n) fxa (v,n)ans=a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m]&a[n]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v],maxx=max(maxx,ans);}
else if (m==22){ fxa (b,n) fxa (c,n) fxa (d,n) fxa (e,n) fxa (f,n) fxa (g,n) fxa (h,n) fxa (i,n) fxa (j,n) fxa (k,n) fxa (l,n) fxa (m,n) fxa (n,n) fxa (o,n) fxa (p,n) fxa (q,n) fxa (r,n) fxa (s,n) fxa (t,n) fxa (u,n) fxa (v,n) fxa (w,n)ans=a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m]&a[n]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v]&a[w],maxx=max(maxx,ans);}
else if (m==23){ fxa (b,n) fxa (c,n) fxa (d,n) fxa (e,n) fxa (f,n) fxa (g,n) fxa (h,n) fxa (i,n) fxa (j,n) fxa (k,n) fxa (l,n) fxa (m,n) fxa (n,n) fxa (o,n) fxa (p,n) fxa (q,n) fxa (r,n) fxa (s,n) fxa (t,n) fxa (u,n) fxa (v,n) fxa (w,n) fxa (x,n)ans=a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m]&a[n]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v]&a[w]&a[x],maxx=max(maxx,ans);}
else if (m==24){ fxa (b,n) fxa (c,n) fxa (d,n) fxa (e,n) fxa (f,n) fxa (g,n) fxa (h,n) fxa (i,n) fxa (j,n) fxa (k,n) fxa (l,n) fxa (m,n) fxa (n,n) fxa (o,n) fxa (p,n) fxa (q,n) fxa (r,n) fxa (s,n) fxa (t,n) fxa (u,n) fxa (v,n) fxa (w,n) fxa (x,n) fxa (y,n)ans=a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]&a[i]&a[j]&a[k]&a[l]&a[m]&a[n]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t]&a[u]&a[v]&a[w]&a[x]&a[y],maxx=max(maxx,ans);}
    if (m<=20)cout<<maxx;
    else cout<<'0';
    Please AC;
}

